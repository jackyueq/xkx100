// qiantang.c �¼���Ǯ��������
// for XKX100 , by Sir 2003.11.3

#include <ansi.h>

// ����
private void do_bonus(object room)
{
        object *obs;
        string msg;
        int lvl,p_bonus,s_bonus;
        int r,i;

        obs = all_inventory(room);
        if (sizeof(obs) < 1)
                return;
	
	msg = HIW "����Ȼ��ۡ�Ǯ��������\n"NOR;
	msg += HIC "ÿ�����ʮ��Ǯ�����ǳ����ǳ�׼ʱ���ʳ�֮Ϊ���š� \n"
	          "ÿ�γ�ˮ����ʱ������ӿ�����Ʊ��ˣ�ʮ��׳�ۡ�\n";NOR;
        msg += HIC "ֻ����¡¡��һ�������������ˮ��ӿһ����򰶱߾�����\n"
                  "ɲ�Ǽ䣬�������ڣ��������꣬�������ţ������ڣ�����\n"
                  "��������ת�ۣ����Լݳ��硣���������ɽ��˪ѩ�С���\n"
                  "׳�����ƣ�����ν��Զ�������Ὥ�������ģ�����ب��ɽ\n"
                  "����������������һʱ���㲻���������У�������ﶼ��Ȼ\n"
                  "�����ˡ�\n" NOR;
                                   
        msg += HIG "��������ӿ�ĳ�ˮ���������򣬶��书�������µ���ᡣ\n" NOR;
        message("vision", msg, obs);

	message("channel:rumor", HIM"��ҥ�ԡ�"+"����ʮ���ֵ��ˣ���˵������ǰ��Ǯ�����۳���\n"NOR, users()); 
	        
        for ( i = 0 ; i < sizeof(obs); i++)  // ����Ǳ�ܻ����ڹ���Ǳ��
                {
                	if( !living(obs[i]) || !userp(obs[i]) ) continue;  
			p_bonus = 5000 + random( 5000 );
			s_bonus = 1000 + random( 500 );
			obs[i]->add("potential", p_bonus);
			obs[i]->add("score",s_bonus);
                        
			lvl = obs[i]->query_skill("force", 1);
                        if (lvl >= 50 && lvl< 300 )
                               	obs[i]->set_skill("force", lvl + 10);
                        else if ( lvl >= 300 )
                               	obs[i]->set_skill("force", lvl + 1);                                	                        
                          
                }
}

// �¼�����
void trigger_event()
{
        object room;
                
        // Ǯ��������
        if (objectp(room = find_object("/d/hangzhou/qiantang")))
                do_bonus(room);
                
}

void create() 
{ 
	seteuid(getuid()); 
	message("channel:sys", HIR"����Ȼ��ۡ�Ǯ�������š�\n"NOR, users());
	trigger_event();
}