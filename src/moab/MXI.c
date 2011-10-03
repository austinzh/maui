/* HEADER */

/* Contains:                                 *
 *                                           */

#include "moab.h"
#include "msched-proto.h"  

extern mlog_t      mlog;

extern mjob_t     *MJob[];
extern mnode_t    *MNode[];

extern mqos_t      MQOS[];
extern mrm_t       MRM[];
extern mam_t       MAM[];

extern mattrlist_t MAList;
extern mrange_t    MRange[];
extern msched_t    MSched;
extern mstat_t     MStat;
extern msim_t      MSim;

extern mgcred_t   *MUser[];
extern mgcred_t    MGroup[];
extern mgcred_t    MAcct[];
extern mres_t     *MRes[];
extern sres_t      SRes[];
extern sres_t      OSRes[];

extern mpar_t      MPar[];

extern long        CREndTime;
extern char        CurrentHostName[];

/* prototypes */

extern int XInitializeMInterface(void *,char *,int *,char **,char *);

extern int LL2ShowError(int,mjob_t *);
extern int LL2FreeData(mrm_t *);


int XInitialize(

  mx_t  *X,
  char  *Version,
  int   *ArgC,
  char **ArgV,
  char  *HomeDir)

  {
# include "MXConfig.c"

# ifdef __MX
  /* enable XInitialize when MG2/MSU are linked in */

  /* XInitializeMInterface(X,Version,ArgC,ArgV,HomeDir); */
# else
  memset(X,0,sizeof(mx_t));
# endif /* __MX */

  return(SUCCESS);
  }  /* XInitialize() */




int XUIJobCtl()

  {  
  const char *FName = "XUIJobCtl";

  DBG(1,fALL) DPrint("INFO:     %s not supported\n",
    FName);

  return(FAILURE);
  }  /* END XUIJobCtl() */



int XUIMetaCtl()

  {  
  const char *FName = "XMetaCtl";

  DBG(1,fALL) DPrint("INFO:     %s not supported\n",
    FName);

  return(FAILURE);
  }  /* END XUIMetaCtl() */




int XUIResCtl()

  {  
  const char *FName = "XUIResCtl";

  DBG(1,fALL) DPrint("INFO:     %s not supported\n",
    FName);

  return(FAILURE);
  }  /* END XUIResCtl() */




int XRMInitialize(

  void  *X,
  mrm_t *R)

  {
  const char *FName = "XRMInitialize";
 
  DBG(1,fALL) DPrint("INFO:     %s not supported\n",
    FName);
 
  return(FAILURE);
  }  /* END XRMInitialize() */




int XPBSNMGetData(

  void    *X,
  mnode_t *N,
  mrm_t   *R)
 
  {
  const char *FName = "XPBSNMGetData";
 
  DBG(1,fALL) DPrint("INFO:     %s not supported\n",
    FName);
 
  return(FAILURE);
  }  /* END XPBSNMGetData() */





int XRMJobResume()

  {  
  const char *FName = "XRMJobResume";

  DBG(1,fALL) DPrint("INFO:     %s not supported\n",
    FName);

  return(FAILURE);
  }  /* END XRMJobResume() */




int XRMJobSuspend()

  {  
  const char *FName = "XRMJobSuspend";

  DBG(1,fALL) DPrint("INFO:     %s not supported\n",
    FName);

  return(FAILURE);
  }  /* END XRMJobSuspend() */





int XUpdateState()

  {
  const char *FName = "XUpdateState";

  DBG(1,fALL) DPrint("INFO:     %s not supported\n",
    FName);

  return(FAILURE);
  }  /* END XUpdateState() */




int XShowConfig(

  void *X,
  char *Buffer)

  {
  /* do nothing */

  return(SUCCESS);
  }  /* END XShowConfig() */




int XAllocMachinePrio()

  {
  const char *FName = "XAllocMachinePrio";

  DBG(4,fALL) DPrint("INFO:     %s not supported\n",
    FName);

  return(FAILURE);
  }  /* END XAllocMachinePrio() */



int XAllocLoadBased()

  {
  const char *FName = "XAllocLoadBased";

  DBG(4,fALL) DPrint("INFO:     %s not supported\n",
    FName);

  return(FAILURE);
  }  /* END XAllocLoadBased() */



int XLL2JobLoad(

  void   *X,
  mjob_t *J,
  void   *LLStep)

  {
  const char *FName = "XLL2JobLoad";

  DBG(6,fALL) DPrint("INFO:     %s not supported\n",
    FName);

  return(FAILURE);
  }  /* END XLL2JobLoad() */



int XLL2JobUpdate(

  void   *X,
  mjob_t *J,
  void   *LLStep)

  {
  const char *FName = "XLL2JobUpdate";

  DBG(6,fALL) DPrint("INFO:     %s not supported\n",
    FName);

  return(FAILURE);
  }  /* END XLL2JobUpdate() */




int XLL2NodeLoad(

  void    *X,
  mnode_t *N,
  void    *LLMachine)

  {
  const char *FName = "XLL2NodeLoad";

  DBG(6,fALL) DPrint("INFO:     %s not supported\n",
    FName);

  return(FAILURE);
  }  /* END XLL2NodeLoad() */



int XLL2NodeUpdate(

  void    *X,
  mnode_t *N,
  void    *LLMachine)

  {
  const char *FName = "XLL2NodeUpdate";

  DBG(6,fALL) DPrint("INFO:     %s not supported\n",
    FName);

  return(FAILURE);
  }  /* END XLL2NodeUpdate() */




int XRMResetState(

  void  *X,
  mrm_t *SpecR)

  {
  const char *FName = "XRMResetState";

  int rmindex;

  mrm_t *R;

  DBG(8,fALL) DPrint("%s(%s)\n",
    FName,
    (SpecR != NULL) ? SpecR->Name : "NULL");

  for (rmindex = 0;rmindex < MAX_MRM;rmindex++)
    {
    R = &MRM[rmindex];

    switch (R->Type)
      {
      case mrmtLL:

        LL2FreeData(R);

        break;

      default:

        break;
      }  /* END switch(tmpR->Type) */
    }    /* END for (rmindex)      */

  return(FAILURE);
  }  /* END XRMResetState() */




int XRMVerifyData(

  void  *X,
  mrm_t *R,
  char  *DataType)

  {
  return(FAILURE);
  }  /* END XRMVerifyData() */



int XPBSInitialize(

  void *X,
  mrm_t *R)

  {
  return(FAILURE);
  }  /* END XPBSInitialize() */



int XUIHandler(

  void      *X,
  msocket_t *S,
  char      *CSKey,
  int        Mode)

  {
  return(FAILURE);
  }  /* END XUIHandler() */



int XGetClientInfo(

  void      *X,
  msocket_t *S,
  char      *CInfo)

  {
  strcpy(S->CSKey,MSched.DefaultCSKey);
  S->Version      = 0;
 
  return(SUCCESS);
  }  /* END XGetClientInfo() */



int XJobProcessWikiAttr(

  void   *X,
  mjob_t *J,
  char   *Tok)

  {
  return(FAILURE);
  }  /* END XJobProcessWikiAttr() */



int XJobDestroy(

  void    *X,
  mjob_t **J,
  int      SC)

  {
  return(SUCCESS);
  }  /* END XJobDestroy() */


/* END MXI.c */

