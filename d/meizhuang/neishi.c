// /d/meizhuang/xiaowu.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��һ��������򵥣����Ϲ��˵�ɴ�ʣ����ŵı��죬������
�¾ɣ��ѳʻ�ɫ�����Ϸ���һ�Ŷ��٣�ͨ����ڣ��������ơ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"xiaowu",
	]));
	set("item_desc", ([
		"chuang" : "����һ�źܳ¾ɵ�ľ����\n" ,
		"��"     : "����һ�źܳ¾ɵ�ľ����\n" ,
		"beiru"  : "����һ�����ڴ��ϵľɱ��졣\n" ,
		"����"   : "����һ�����ڴ��ϵľɱ��졣\n" ,
	]));
	set("coor/x", 3510);
	set("coor/y", -1410);
	set("coor/z", 20);
	setup();
}

void init()
{
        add_action("do_move", "xian");
        add_action("do_move", "move");
        add_action("do_open", "open");
        add_action("do_open", "ti");
}
int do_move(string arg)
{
	object me = this_player();

	if (!arg||arg!="beiru") return notify_fail("��Ҫ�ƿ�ʲô��\n");
	if ( query("beiru") )
		return notify_fail("�����Ѿ��ƿ��ˣ����ƾ͵������ˣ�\n");
	message_vision("$N�ƿ����ϱ��죬���𴲰壬����ȴ�ǿ����壬����ͭ����\n", me);
	set("beiru", 1);
	return 1;
}

int do_open(string arg)
{
	object midao1, me = this_player();

	if (!arg||arg!="tieban") return notify_fail("��Ҫ�Ὺʲô��\n");
	if (me->query("neili") < 200)
	{
		message_vision("$N��סͭ��������һ�ᣬ�����Ʒ粻����\n", me);
		me->set("neili", 0);
		return 1;
	}
	me->add("neili", -200);
	if(!( midao1 = find_object(__DIR__"midao1")) )
		midao1 = load_object(__DIR__"midao1");
        if(objectp(midao1))
        {
		set("exits/down", __DIR__"midao1");
		message_vision("$N��סͭ��������һ�ᣬһ���ĳ��������������������Ӧ�ֶ���¶��һ�����󷽶���\n", me);
		midao1->set("exits/up", __FILE__);
                message("vision","ͷ��͸��һ��⣬�������������˴������ˡ�\n", midao1);
                remove_call_out("close_gate");
                call_out("close_gate", 5);
        }
	return 1;
}
void close_gate()
{
	if( !query("exits/down") ) return;
	message("vision","����������, �������ڵ�����ʵʵ�ġ�\n", this_object());
	delete("exits/down");
}



