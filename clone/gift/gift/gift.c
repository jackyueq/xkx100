#include <ansi.h>
inherit ITEM;

int query_autoload()
{
        return 1;
}

void create()
{
        set_name(HIY "�ɵ�" NOR, ({ "gift" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "����һ��������ò���ɵ���\n" NOR);
                set("unit", "��");
                set("value", 10000);
                set("weight", 50);

                // �����츳������
                set("gift_type", "per");

                // �츳���������
                set("gift_name", "��ò");

                // �ɹ��ļ���
                set("gift_point", 100);

                // �ɹ�������
                set("gift_msg", HIC "ͻȻ�����Ƥ��͸��һ������\n" NOR);
        }
        setup();
}
init()
{
	add_action("do_eat","eat");
	}
int do_eat(string arg)
{
     int point=query("gift_point");
     int max,top;
     object me=this_player();

			if (!id(arg)) 	return 0;
			if (me->is_busy()) 
			{
			write("����æ���ء�\n");
			return 1;
			}
				//�����������ؿ��Ե��ڳɹ���
				
//     max = 10 + SCBORN_D->query_scborn_times(me) * 5;
     max = 10;
     if (SCBORN_D->query_scborn_times(me) == 6 ) max = 10000;
     top = 35 + SCBORN_D->query_scborn_times(me) * 5;
        message_vision(WHT "$N" WHT "һ������������һ" +
                       query("unit") + name() + WHT
                       "��\n" NOR, me);

        if (me->query("gift/" + query("gift_type") + "/all") >= max 
        	|| me->query(query("gift_type"))>=top)
        {
                tell_object(me, "�������ҩ����ûʲôЧ����\n");
        } else
        if (random(100) >= point)
        {
                tell_object(me, HIR "�����������ҩ����û��ʲô"
                                "���á�\n" NOR);

                // ��¼ʧ�ܵļǺ�
                me->add("gift/" + query("gift_type") + "/fail", 1);
                log_file("gift/eat_dan",sprintf("%-20s eat %-10s(%s) fail [%s]\n",me->query("name")+"("+me->query("id")+")",this_object()->name(),this_object()->query("gift_type"),ctime(time())));
		     } 
		     else
       {
                tell_object(me, query("gift_msg"));
                tell_object(me, HIC "���" + query("gift_name") +
                                HIC "��������һ�㡣\n" NOR);

                // ��¼�ɹ��ļǺ�
                me->add("gift/" + query("gift_type") + "/succeed", 1);
                log_file("gift/eat_dan",sprintf("%-20s eat %-10s(%s) success [%s]\n",me->query("name")+"("+me->query("id")+")",this_object()->name(),this_object()->query("gift_type"),ctime(time())));
		            log_file("gift/tianfu",
		                     sprintf("%-20s ����%-10s������%s(%s) [%s]\n",
		                     me->query("name")+"("+me->query("id")+")",
		                     base_name(this_object()),
		                     query("gift_name"),query("gift_type"),ctime(time())));        
 
                // ������Ӧ���츳����
                me->add(query("gift_type"), 1);
        }

        // ��¼��Ե�������
        me->add("gift/" + query("gift_type") + "/all", 1);
        destruct(this_object());
        return 1;
}

