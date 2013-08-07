// Room: /d/yanziwu/tingyu.c
#include <ansi.h> 
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���С�ӽ��ں��ϣ�����ȥû��ʲô�ر�֮��������Ϊˮ��������
�������۵ס�Ψһ��ֵ����������һ������(qin)��
LONG );
	set("item_desc", ([
	    "qin" : "���ٱ�֮Ѱ�������ٶ��˳���ȴ�оŸ����ҡ�\n"
		     "��֪�Ǹ�ȥ��һ��(tan)���ǽ�������(break)��\n",
	]));
	set("objects", ([
	    __DIR__"obj/shigu"   : 1,
	    __DIR__"obj/xianglu" : 1,
	]));
	set("exits", ([
	    "south" : __DIR__"xiaoqiao",
	]));
	set("no_clean_up", 0);
	set("coor/x", 810);
	set("coor/y", -1480);
	set("coor/z", 10);
	setup();
}


void init()
{
	add_action("do_tan", "tan");
	add_action("do_tan","play");
	add_action("do_break","break");
}

int do_tan (string arg)
{
	object room;
	object ob = this_player();
	if (!arg||arg!="qin") return notify_fail("��Ҫ��ʲô��\n");
	message_vision("$N�����������һ��������һ����������Ϊ������\n\n"
		+"�ƺ������е�Ź�.....\n"
		+"$N�����Ƽ䣬�����ŵ�һ�飬��������ֱ��.....\n", ob );
	tell_object(ob, "\n���̲�ס��Ӵһ�����������һ������������ڣ�ԭ����һ��С����\n\n" ) ;
	room=load_object("d/yanziwu/hu");
	ob->move(room) ;

	call_out("mantuo", 10 , ob );
	return 1 ;
}

int do_break(string arg)
{
	if (!arg||arg!="qin") return notify_fail("��Ҫ����ʲô��\n");
	message_vision(
		"\n$Nһ�ƻ������٣�ֻ����ৡ���һ��,ͻȻ����һ����\n"+
		"һö÷����ٿ�����,���ۡ���һ��������$N������Ѩ��\n", this_player());
	if((int)this_player()->query("qi")<200) this_player()->die();
	else this_player()->unconcious();
	return 1;
}

int mantuo( object ob )
{
	if (ob->query("family/family_name") == "����Ľ��")
	{
		tell_object(ob, "\nС��ת��һ��"HIG"����"NOR"��ԶԶ����"HIC"ˮ��"NOR"һ��"HIR"����"HIM"ӳˮ���죬������ϼ"NOR"��\n�㲻����������һ���ͺ���ãȻ�Ŀ������ܣ����´�����\n\n") ;
		ob -> move (__DIR__"chalin");
	}
	else
		ob -> move (__DIR__"hupan");
	return 1;
}