// hspb.c �¼�����ɽˮ�����ٲ�
// for XKX100 , by Sir 2003.11.3

#include <ansi.h>

// ����
private void do_bonus(object room)
{
        object *obs;
        object ob;
        string msg;
        int lvl,p_bonus,s_bonus;
        int r,i;

        obs = all_inventory(room);
        if (sizeof(obs) < 1)
                return;

        r = random(365);
        if (r == 0)
        { 
        	msg = HIY "����Ȼ��ۡ���ɽˮ��������\n"NOR;
                msg += HIG "ֻ����¡¡�������������������������ľ���ҡ����̧ͷ��ȥ��ֻ��\n"
                          "�ƻ���ˮ���������ڲ������֮�У�������次�����ˮ����к�����ƾ��ˣ�\n" NOR;
                msg += HIG "�������ļ����ٲ�������Ϊ������������̾���ѣ���"
                           "�в�����������ѧ�ĵ���\n" NOR; 
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

                message("vision", msg, obs);
                message("channel:rumor", HIM"��ҥ�ԡ�"+"��˵��ɽˮ�����ٲ��������ȣ��澰�Ƿ�����������̾�۲��ѡ�\n"NOR, users());
               
        } else 
        if (r < 250) 
        {	
        	msg = HIY "����Ȼ��ۡ���ɽˮ��������\n"NOR;
                msg += HIY "һ���¡��¡��������������̧ͷһ����ֻ���ƻ����ٲ�������������\n" NOR;
                switch (random(3)) 
                { 
                case 0: 
                        msg += HIY "������׳�����������㲻����̾������ν������ֱ"
                                    "����ǧ�ߣ�������������졹����\n" NOR; 
                        break; 
                case 1: 
                        msg += HIY "��������һϯ���ҵİ�����������磬��ض�����Ϊ֮ʧɫ��\n" NOR; 
                        break; 
                default: 

                        msg += HIY "����ֱ��ˮ��й��һ�㣬ˮ���Ľ���\n" NOR; 
                        break; 
                } 
                msg += HIG "�����ŷ���ֱ�µ�ˮ�٣��㲻�ɵø�̾��Ȼ�컯�������"
                           "������ѧҲ����һ����ᡣ\n" NOR; 
                           
                for ( i = 0 ; i < sizeof(obs); i++)
                {
                	if( !living(obs[i]) || !userp(obs[i]) ) continue;
			p_bonus = 500 + random( 500 );
			s_bonus = 200 + random( 200 );			
			obs[i]->add("potential", p_bonus);
			obs[i]->add("score", s_bonus);
		}               
 
                message("vision", msg, obs);

        } else
        {
                switch (random(3))
                {
                case 0:
                        msg = WHT "������������������\n" NOR;
                        break;
                case 1:
                        msg = WHT "�������ǲ�������ǿ�����ơ�\n" NOR;
                        break;
                default:
                        msg = WHT "��������С����ˮ���������ˣ������������������Զ��\n" NOR;
                        break;
                }
                msg += HIG "�����д��ʧ����\n" NOR;

                message("vision", msg, obs);
        }
} 
 
// �¼����� 
void trigger_event() 
{ 
        object room; 
        // ��ɽˮ�����ٲ� 
        if (objectp(room = find_object("/d/henshan/shuiliandong"))) 
                do_bonus(room); 
} 

void create() 
{ 
	seteuid(getuid()); 
	message("channel:sys", HIR"����Ȼ��ۡ���ɽˮ�����ٲ���\n"NOR, users());
	trigger_event();
}