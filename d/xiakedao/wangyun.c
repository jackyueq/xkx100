// wangyun.c ����̨

inherit ROOM;

#include <ansi.h>
int do_take(string arg);

void create()
{
        set("short", "����̨");
        set("long", @LONG
����������͵���ߵ� "����̨" �������������Զ���󺣣�
�����õ�ʱ���ܿ���һ���澰-- "�ƺ�" ����ʯ��֮�䳤��һ��
�������׳� "������" ����������Χ����ǿ�������ż���С��(cao)��
LONG    );
        set("exits", ([
                "northdown" : __DIR__"road8",
        ]));
        set("outdoors", "xiakedao" );
        set("item_desc",([
            "cao" : "������̵�С�ݣ��㲻������(take)������\n"
        ]) );
        set("no_clean_up", 0);
        set("caocount", 1);
	set("coor/x", -3110);
	set("coor/y", -22150);
	set("coor/z", 40);
	setup();
}

void init()
{
        add_action("do_take","take");
}
int do_take(string arg)
{
        object me=this_player();
        object obn;
        int n;
        n = this_player()->query_skill("dodge",1);
        if( !arg || arg != "cao" )
        {
             write("��Ҫ��ʲôѽ!\n");
             return 1;
        }
message_vision("$N������ǰվ�������һ������ͻȻԾ��\n", this_player());
        if(n >=80)
        {
             if(query("caocount") > 0)
             {
message_vision("ֻ��$N�������ڿ��д��˼���������������ƮƮ��أ����ж���һ�\n", this_player());
                 obn = new("/clone/medicine/vegetable/fuxincao");
                 obn->move(me);
                 add("caocount",-1);
             }
             else
message_vision("$N����һ�������ֲ��类�������ˡ�\n", this_player());
        }
        else
        {
             me->receive_damage("qi", 50);
             me->receive_wound("qi", 50);
             message_vision(HIR" ֻ��$N�������ڿ��д��˼���������ѽ! ����!!!!\n"NOR, this_player());
             me->move(__DIR__"gudi");
             tell_object(me,HIR"���������ˤ��������������ʹ�������˼����ˡ�" NOR);
message("vision", HIR "ֻ��" + me->query("name") + "���������ˤ��������
���ڵ��ϣ�����Ҳ���ܶ���\n" NOR, environment(me), me);
        }
        return 1;
}
