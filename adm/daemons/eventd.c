// eventd.c
// ��Ȼ���ϵͳ������
// for XKX100 , by Sir 2003.11.3

#include <dbase.h>
#include <ansi.h>
#include <localtime.h>
int start;

// ���������¼�
// �Ǽ���ĳ�����Ե�ʱ�������¼�
// �趨�Ĳ����������
// ���磺month = 0  day = 0   hour = -5    ��ʾʵ��ʱ��ÿ������5���� 
//	 month = -8 day = -15 hour = -5    ��ʾʵ��ʱ��ÿ��8��15��5���� 
mapping *event_list = ({	
(["month" :  0, "day" :  0, "hour"  : -7,  "ename"  : "emei.c",     "cname" : "���ҽ��ճ�" ]), //����7��
(["month" :  0, "day" : -15,"hour"  : -23, "ename"  : "wuliang.c",  "cname" : "����ɽ��ڽ���"]), //ÿ��15����11��
(["month" :  0, "day" :  0, "hour"  : -22, "ename"  : "tianchi.c",  "cname" : "����ɽ�������"]), //ÿ��10��
(["month" : -8, "day" : -15,"hour"  : -10, "ename"  : "qiantang.c", "cname" : "Ǯ��������"]), //ÿ��8��15��10��
(["month" :  0, "day" :  0, "hour"  : -17, "ename"  : "hspb.c",     "cname" : "��ɽˮ�����ٲ�"]), //ÿ������5��
});


void create()
{
        int i;
        seteuid(ROOT_UID);

        message("channel:sys", HIR"����Ȼ��ۡ���Ȼ����Ѿ�������\n"NOR, users());
        message("channel:sys", HIR"����Ȼ��ۡ�ϵͳ�ѵǼǵ���Ȼ�������:\n"NOR, users());
        
        for ( i = 0 ; i < sizeof(event_list); i++)
        {
        	message("channel:sys", HIR"����Ȼ��ۡ�"+event_list[i]["cname"]+"��\n"NOR, users());
        }
        
        set_heart_beat(30);      // ÿ��������һ��
}


// ÿ��������һ�Σ�1,10ʱ������е��¼�
void heart_beat()
{
        mixed *lt;
        object eob;
        int  tt,i,num;
        int  month,day,hour;
        string time;
        
        lt = localtime(time());
        num = 0;
        
        if ( start == 59 ) 
             { 
             	start = 0;
              }
        else start = start + 1; 
        
        time = ""; 
        
        time = chinese_number( start );
        
//        message("channel:sys",HIR"����Ȼ��ۡ� ���ʱ���������"+time+"��\n"NOR, users());
        
        if ( start == 1 || start == 10) 
        {      
        
        for ( i = 0 ; i < sizeof(event_list); i++)
        	{
        		month = event_list[i]["month"];
        		day   = event_list[i]["day"];
        		hour  = event_list[i]["hour"];
        			
        		if (month < 0) month = -month-1; 
        			else month += lt[LT_MON] ;
        		if (day < 0)   day = -day;     
        			else day += lt[LT_MDAY];
        		if (hour < 0)  hour = -hour;   
        			else hour += lt[LT_HOUR];
        	if (  month == lt[LT_MON] && day == lt[LT_MDAY] && hour == lt[LT_HOUR])
      	  		{
        		    if (start == 1)
        		    message("channel:rumor", HIM"��ҥ�ԡ�"+"��˵"+event_list[i]["cname"]+"εΪ��ۣ����ٽ�����ʿ�׷�ǰ�����͡�\n"NOR, users());
        		    else
        		    {
        		    	eob = new (EVENT_DIR + event_list[i]["ename"]);
        		    	destruct(eob);
        		    }	        
        		 }
        	else
        		continue;
        	}
        } 
}
