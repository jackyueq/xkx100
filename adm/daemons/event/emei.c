// emei.c �¼������ҽ��ճ�
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

        r = random(365);
        if (r == 0)
        {
                msg = HIY "����Ȼ��ۡ����ҷ��\n"NOR;
                msg += HIR "ֻ��̫��һ��һ�������������ٿ����ǰһ����һ�����γ������Ƽʣ�\n"
                          "���������ƺ���һ����Ӱ���ڵ��У�����̾�۲��ѡ�\n" NOR;
                msg += HIG "��ڤڤ�з·�õ��˷�����ָʾ����ʱ��é���ٿ��ĸо���\n" NOR;
                
               
               

                // ���ŵ������ӷ�ѧ����
                for ( i = 0 ; i < sizeof(obs); i++)
                {
                	if( !living(obs[i]) || !userp(obs[i]) ) continue;
			p_bonus = 5000 + random( 5000 );
			s_bonus = 1000 + random( 500 );
			obs[i]->add("potential", p_bonus);
			obs[i]->add("score",s_bonus);
                        if (obs[i]->query("class") == "bonze")
                           {
				lvl = obs[i]->query_skill("buddhism", 1);
                        	if (lvl >= 50 && lvl< 200 )
                                	obs[i]->set_skill("buddhism", lvl + 1);
                                
				lvl = obs[i]->query_skill("mahayana", 1);
                        	if ( lvl >= 50 && lvl < 200)
                                	obs[i]->set_skill("mahayana", lvl + 1);
				lvl = obs[i]->query_skill("lamaism", 1);
                        	if (lvl >= 50 && lvl <200 )
                                	obs[i]->set_skill("lamaism", lvl + 1);
                            }
                }

                message("vision", msg, obs);
		message("channel:rumor", HIM"��ҥ�ԡ�"+"��˵���ҽ𶥷����֣�����̾Ϊ��ֹ����̾���ѡ�\n"NOR, users());
               
        } else
        if (r < 250)
        {
        	msg = HIY "����Ȼ��ۡ������ճ�\n"NOR;
        	msg +=HIG "�ڶ���ɽ�������ճ������Ŀ��������������Զ���ɽ���������档\n"NOR;
        	
                switch (random(3))
                {
                case 0:
                        msg += HIY "һ�ֺ���Ծ����ʣ�ӳ��ò��͵��������欣�ãã�ƺ���������ױ��\n" NOR;
                        break;
                case 1:
                        msg += HIY "��Ȼ��һ�ֺ���Ծ�����������֮���ʱ�Ի��ޱȣ�ֻ������۾����޷�������\n" NOR;
                        break;
                default:
                        msg += HIY "��Ȼ��ǰ������䣬һ�ֺ���ȽȽ����\n" NOR;
                        break;
                }
                msg += HIG "����ͷ����һ����⣬�ƺ��ܵ���ĳ�����ϡ�\n" NOR;
                
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
                        msg = WHT "�ۼ�̫���������ʵľ�Ҫ��������ȴ��һƬ����Ʈ�������˸�����ʵʵ��\n" NOR;
                        break;
                case 1:
                        msg = WHT "����ǰԽ��Խ���������������أ�����ʲô�����������\n" NOR;
                        break;
                default:
                        msg = WHT "��߽����ķ��ף�����һ��һ�����������ͷѹ�ù�âһ˿����������\n" NOR;
                        break;
                }
                msg += HIG "��������̾����̫��ϧ�ˣ���\n" NOR;

                message("vision", msg, obs);
        }
}

//�¼�����
void trigger_event()
{
        object room;

        // ���ҽ��ճ�
        if (objectp(room = find_object("/d/emei/jinding")))
                do_bonus(room);
}

void create() 
{ 
	seteuid(getuid()); 
	message("channel:sys", HIR"����Ȼ��ۡ����ҽ��ճ���\n"NOR, users());
	trigger_event();
}