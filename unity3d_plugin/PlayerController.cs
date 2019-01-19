using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

using System.Runtime.InteropServices;

public class PlayerController : MonoBehaviour
{
    public float thrust;
    public Text countText;
    public Text winText;

    private Rigidbody rb;
    Renderer rend;
    Material mMaterial;
    private float clickTime;
    private Vector3 movement;
    private static int count;
    private int mPersonId;
    int mFlipArousal = 1;

    // Start is called before the first frame update
    void Start()
    {
        rb = GetComponent<Rigidbody>();
        rend = GetComponent<Renderer>();
        //Fetch the Material from the Renderer of the GameObject
        mMaterial = GetComponent<Renderer>().material;
        clickTime = 0.0f;
        count = 0;
        SetCountText();
        winText.text = "";
        mPersonId = EModLibWrapper.createPersonEx(0);
        Debug.Log("PersonID " + mPersonId);
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey("escape"))
        {
            Application.Quit();
        }

        //Set the main Color of the Material to valence
        double valence = EModLibWrapper.getValenceEx(mPersonId);
        //rend.material.shader = Shader.Find("_Color");
        
        if (valence > 0.1)
        {
            
            //rend.material.SetColor("_Color", Color.blue);
            mMaterial.color = new Color(0.0f, 0.0f, 1.0f);
        }
        else if (valence < -0.1)
        {
           
            //rend.material.SetColor("_Color", Color.red);
            //mMaterial.color = Color.red;
            mMaterial.color = new Color(1.0f, 0.0f, 0.0f);
        }
        else
        {
          
            mMaterial.color = new Color(0.0f, 1.0f, 0.0f);
        }

        rb.drag = (float)EModLibWrapper.getValenceEx(mPersonId) + 1.0f;
    }

    void OnMouseDown()
    {
        clickTime = Time.time;

        Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
        RaycastHit hit;

        //if (Physics.Raycast(ray))
        // (Physics.Raycast(transform.position, transform.TransformDirection(Vector3.forward), out hit, Mathf.Infinity, layerMask))
        if (GetComponent<Collider>().Raycast(ray, out hit, Mathf.Infinity))
        {
            movement = (transform.position - hit.point).normalized;
        }

        Debug.Log("Pressed mouse down button.");
    }

    void OnMouseUp()
    {
        float arousal = Time.time - clickTime;
        mFlipArousal *= -1;
        if (Input.GetMouseButtonUp(0))
        {
            EModLibWrapper.inStimulusEx(mPersonId, arousal * mFlipArousal, Random.Range(-1.0f, 1.0f));
            Debug.Log("Stimulus: " + arousal + " random valence");
        }
        
        rb.AddForce(movement * thrust * arousal);
        Debug.Log("Pressed mouse up button.");
    }

    void OnCollisionEnter(Collision other)
    {
        if (other.gameObject.CompareTag("NegativeWall") && (EModLibWrapper.getValenceEx(mPersonId) < -0.1))
        {            
            gameObject.SetActive(false);
            count++;
            SetCountText();
            Debug.Log("Collision.");
        }
        else if (other.gameObject.CompareTag("PositiveWall") && (EModLibWrapper.getValenceEx(mPersonId) > 0.1))
        {
            gameObject.SetActive(false);
            count++;
            SetCountText();
            Debug.Log("Collision.");
        }
        else if (other.gameObject.CompareTag("NeutralWall") && (EModLibWrapper.getValenceEx(mPersonId) > -0.1) && (EModLibWrapper.getValenceEx(mPersonId) < 0.1))
        {
            gameObject.SetActive(false);
            count++;
            SetCountText();
            Debug.Log("Collision.");
        }
    }

    void SetCountText ()
    {
        countText.text = "Count: " + count.ToString();
        if (count >= 8)
        {
            winText.text = "You Win!!!";
        }
    }

    void OnDestroy()
    {
        //Destroy the instance
        Destroy(mMaterial);
    }
}
