<?php

namespace App\Controllers;

use App\Controllers\BaseController;
use App\Models\SignModel;

class IdController extends BaseController
{
    public function index()
    {
        return view('id/index.php');
    }
    public function redirectTo(){
        return view("id/{$this->request->getVar('where')}.php");
    }
    public function studentSignIn(){
        $model=new SignModel();
        $data=[
            'username'=>$this->request->getVar('username'),
            'password'=>$this->request->getVar('password')
        ]; 

    }
    public function studentRegistration()
    {   
        $model=new SignModel(); 
        $data=[
            'fullname'=>$this->request->getVar('fullname'),
            'username'=>$this->request->getVar('username'),
            'password'=>$this->request->getVar('password')
        ];
        $YN=$model->save($data);
        return redirect("idController");
    }
}
