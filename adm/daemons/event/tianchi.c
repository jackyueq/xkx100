// emei.c �¼�������ɽ�������
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
        	msg = HIW "����Ȼ��ۡ����������\n"NOR;
                msg += HIC "ֻ�������Ȼ����һ��̶���Ħ�������������ϲԣ����������ѻ�Ȼ����\n"
                           "���������ǡ�ҹ�������׹����â���գ����������֮�У����ټ��������\n"
                           "ɫ���Σ����ҹ񷾹�������һ�㡣�㲻����̾������Ȼ֮�����������Ī\n"
                           "�⡣\n" NOR;

                msg += HIG "����ϸ�Ĺ۲����������ȫ���̣��������о��кܶ���ؿ���������ѧ��\n" NOR;
                
                for ( i = 0 ; i < sizeof(obs); i++)  // ����Ǳ�ܻ����Ṧ��������
                {
                	if( !living(obs[i]) || !userp(obs[i]) ) continue;                
			p_bonus = 5000 + random( 5000 );
			s_bonus = 1000 + random( 500 );
			obs[i]->add("potential", p_bonus);
			obs[i]->add("score",s_bonus);
                        
			lvl = obs[i]->query_skill("throwing", 1);
                        if (lvl >= 50 && lvl< 300 )
                               	obs[i]->set_skill("throwing", lvl + 10);
                        else if ( lvl >= 300 )
                               	obs[i]->set_skill("throwing", lvl + 1);
                                	
                        lvl = obs[i]->query_skill("dodge", 1);
                        if (lvl >= 50 && lvl< 300 )
                               	obs[i]->set_skill("sword", lvl + 10);
                        else if ( lvl >= 300 )
                               	obs[i]->set_skill("sword", lvl + 1);
                }
                
                
                message("vision", msg, obs);
                message("channel:rumor", HIM"��ҥ�ԡ�"+"��˵����ɽ�����ҹ�վ��������꣬����ͷף�ɷΪ׳�ۡ�\n"NOR, users());
        } else
        if (r < 40)
        {
        	msg = HIW "����Ȼ��ۡ�ҹ������\n"NOR;
                msg += HIC "ֻ��Զ��һ��̶���Ħ��������Ŀ��ȥ�����־������Ǵ���߻��������ξ�\n"
                          "��ίʵ̫Զ�������޷����塣\n" NOR;

                msg += HIG "��۰����ǣ������Ķ���ѧ����һ˿��ᡣ\n" NOR;

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
                switch (random(2))
                {
                case 0:
                        msg = WHT "�ۼ����һƬ������֪�������꽫���������μ��ң���Ʋ��ȴ��Ե�ü���\n" NOR;
                        break;
                default:
                        msg = WHT "�ۼ����һƬ����������ˮ�����������Ʋ㽻�ӣ�����ʲô�����������\n" NOR;
                        break;
                }
                msg += HIG "��������̾����̫��ϧ�ˣ���\n" NOR;

                message("vision", msg, obs);
        }
}

// �¼�����
void trigger_event()
{
        object room;

        // ����ɽ���ҹ��
        if (objectp(room = find_object("/d/guanwai/tianchi1")))
                do_bonus(room);
}

void create() 
{ 
	seteuid(getuid()); 
	message("channel:sys", HIR"����Ȼ��ۡ�����ɽ������ǡ�\n"NOR, users());
	trigger_event();
}
