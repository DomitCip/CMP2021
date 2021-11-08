
void events(){

  TFile out("output.root","RECREATE");
  TTree* prt= new TTree("prttree","particle tree");

  TCanvas* c1=new TCanvas("c1","c1",300,10,600,600);

  TLorentzVector pb;
  pb.SetXYZM(300.,0.,0.,5279.);
  
  Double_t boost= 300./5279.;
  Double_t gamma= 1/TMath::Sqrt(1-boost*boost);
  Double_t invmass=0.; 
 TLorentzVector pp;
  TLorentzVector pk;
  TBranch* Momb=prt->Branch("pb",&pb);
  TBranch* Momp=prt->Branch("pp",&pp);
  TBranch* Momk=prt->Branch("pk",&pk);

  TBranch* Invmass=prt->Branch("invmass",&invmass,"invmass/D");


 Double_t mb2= pb.M()*pb.M();
 Double_t mp2= pp.M()*pp.M();
 Double_t mk2= pk.M()*pk.M();     //Various exps of masses
 Double_t mb4=mb2*mb2;  
 Double_t mp4=mp2*mp2;
 Double_t mk4=mk2*mk2;
 Double_t norm=TMath::Sqrt((mb4+mp4+mk4-2*mb2*mp2-2*mb2*mk2-2*mk2*mp2)/(2*mb2));
 TLorentzVector ptot;

 TRandom* Dir=new TRandom;
 Dir->GetSeed();

 out.cd();
 for(int i=0;i<1000;i++){
   ptot.SetXYZM(0.,0.,0.,0.);
   pp.SetXYZM(0.,0.,0.,0.);
   pk.SetXYZM(0.,0.,0.,0.);
   
   Dir->TRandom::Sphere(pp(0),pp(1),pp(2),norm);
   pk(0)=(-1)*pp(0);
   pk(1)=(-1)*pp(1);
   pk(2)=(-1)*pp(2);
   pp.SetE(TMath::Sqrt(140.*140.+norm*norm));
   pk.SetE(TMath::Sqrt(500.*500.+norm*norm)); 
   
   // pp.Boost(boost,0.,0.);
   //pk.Boost(boost,0.,0.);
   //cout<< pp(1)<<"     "<< pk(1)   <<"  pre     "<<   ptot(1)   <<endl; 
   cout<< boost<<"      "<<gamma<<endl;

   pp(0)=gamma*(pp(3)+boost*pp(0));
   pp(3)=gamma*(pp(0)+boost*pp(3));

   pk(0)=gamma*(pk(3)+boost*pk(0));
   pk(3)=gamma*(pk(0)+boost*pk(3));

   ptot(0)= pp(0)+pk(0);
   ptot(1)= pp(1)+pk(1);
   ptot(2)= pp(2)+pk(2);
   ptot(3)= pp(3)+pk(3);   
   // cout<< pp(1)<<"     "<< pk(1)   <<"  post     "<<   ptot(1)   <<endl; 

   invmass=ptot.M();
   
   prt->Fill();

}
 c1->cd(1);
 Invmass->Draw();

  prt->Write("prttree");

  out.Close();
}
