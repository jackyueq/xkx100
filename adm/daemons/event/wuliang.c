// wuliang.c �¼�������ɽ��ڽ���
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

        r = random(100);
        if (r == 0)
        {
        	msg = HIG "����Ȼ��ۡ�����ɽ��ڽ���\n"NOR;
                msg += HIW "ֻ������¹��£�����Ʈ�ݾ��׵���Ӱ��ӳ�ڶ���ɽ��֮�ϣ��ֽ�������\n"
                           "�裬����ٴ죬��Ӱ���衣�㲻�ɾ�̾�����֮�У�������˾���֮������\n"
                           "����Ե�ü�����֮�ˣ�ʵ���Ǹ��ַ�ǳ��\n" NOR;
                msg += HIG "������˵Ľ����������У���ѧ�϶�ʱ�����µ�����\n" NOR;

                message("vision", msg, obs);
		for ( i = 0 ; i < sizeof(obs); i++)  // ����Ǳ�ܻ���������������
                {
                	if( !living(obs[i]) || !userp(obs[i]) ) continue;
			p_bonus = 5000 + random( 5000 );
			s_bonus = 1000 + random( 500 );
			obs[i]->add("potential", p_bonus);
			obs[i]->add("score",s_bonus);
                        
			lvl = obs[i]->query_skill("sword", 1);
                        if (lvl >= 50 && lvl< 300 )
                               	obs[i]->set_skill("sword", lvl + 10);
                        else if ( lvl >= 300 )
                               	obs[i]->set_skill("sword", lvl + 1);
                                	
                        lvl = obs[i]->query_skill("dodge", 1);
                        if (lvl >= 50 && lvl< 300 )
                               	obs[i]->set_skill("dodge", lvl + 10);
                        else if ( lvl >= 300 )
                               	obs[i]->set_skill("dodge", lvl + 1);
                          
                }
                message("channel:rumor", HIM"��ҥ�ԡ�"+"��˵��������ɽ�ֳ����˽��裬��Ӱ���棬���˷�����˼��\n"NOR, users());        
        } else
        if (r < 60)        
        {	
        	msg = HIG "����Ȼ��ۡ�����ɽ�����Ӱ\n"NOR;
        	msg += HIW"����¹��£�����������ԼԼ��Ӱ������֮�ˡ�ʵ��������С�\n"NOR;
        	
                switch (random(3))
                {
                case 0:
                        msg += HIW "ֻ����������ɽ�������Ӱһ������������֮���ݣ���������޷���׽��\n" NOR;
                        break;
                case 1:
                        msg += HIW "ֻ������ɽ���������������Ӱ���ƺ���ʩչһ�������ޱȵ��书��ѧ��\n" NOR;
                        break;
                default:
                        msg += HIW "��Ȼ������Ʈ�ݾ��׵���Ӱ��ӳ�ڶ���ɽ�ϣ�����Ӱת˲���ţ�������޷����塣\n" NOR;
                        break;
                }
                msg += HIG "���ܵ�����Ӱ�ĸ�����ѧ����������һЩ��ᡣ\n" NOR;
                
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
                        msg = WHT "�ۼ�����¹����𣬿���һ����Ʈ�����ڸ����¹⣬����ǰ��ʱһƬ��ڡ�\n" NOR;
                        break;
                case 1:
                        msg = WHT "��Ŀ��ת����ע���Ŷ������ڣ���ɲ�Ǽ�����������ɽ����ƣ����¹����˸���ʵ��\n" NOR;
                        break;
                default:
                        msg = WHT "ҹ����������һ����Ũ����Ʋ�ȴ��������գ����������ɽͷ���޷����塣\n" NOR;
                        break;
                }
                msg += HIG "�㲻��̾Ϣ����������Ե��δ������Ե������Ӱ����\n" NOR;

                message("vision", msg, obs);
        }
}

// �¼�����
void trigger_event()
{
        object room;

        // ����ɽ��ڽ���
        if (objectp(room = find_object("/d/xiaoyao/pubu")))
                do_bonus(room);
}

void create() 
{ 
	seteuid(getuid()); 
	message("channel:sys", HIR"����Ȼ��ۡ�����ɽ��ڽ��衣\n"NOR, users());
	trigger_event();
}