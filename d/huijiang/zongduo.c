// Room: /d/huijiang/zongduo.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;
#include <ansi.h>;

int flag=0;
int get=1;
void hit();
void create()
{
	set("short", "�컨���ܶ�");
	set("long", @LONG
�����Ǻ컨����ܶ棬������վ���˺컨��ĵ��ӡ����ǵ����ϱ�
�����£�ÿ���˵����ֶ��������Լ��ı��У��м�����ӿ��ţ�������
�����¼��岻�ڣ����Ե���¯(xiang lu)ɢ�������Ե����̣����ǳ���
��һ����ʥ�ķ�Χ��
LONG );
	set("valid_startroom", 1);	
	set("exits", ([
		"southdown" : __DIR__"zoulang2",
		"west"      : __DIR__"goldroom",
	]));
	set("item_desc", ([
		"xiang lu" : "һ����ɫ�������ͭ��¯��һ�ɵ��������������治ʱ��ð������\n",
	]));
	set("objects", ([
		CLASS_D("honghua")+"/wu-chen" : 1,
		CLASS_D("honghua")+"/zhao-banshan" : 1,
		__DIR__"npc/dizi" : 2,
	]));
	set("coor/x", -50070);
	set("coor/y", 9150);
	set("coor/z", 20);
	setup();
	"/clone/board/honghua_b"->foo();
}
void init()
{
	add_action("do_tui", "tui");
	add_action("do_tui", "move");
	add_action("do_wedge", "insert");
	add_action("do_wedge", "wedge");
}
int do_tui(string arg)
{
	object me=this_player();

	if(!arg || arg!="xiang lu")
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->query("combat_exp") < 200000 )
		return notify_fail("��Ĺ���̫��޷��ƶ���¯��\n");
	else if ( flag==0 )
		{
			flag=1;
			message_vision("ֻ�������ꡱһ�죬��¯���ֳ�һ��С����\n", me);
			set("item_desc", ([
				"xiang lu" : "һ����ɫ�������ͭ��¯��һ�ɵ��������������治ʱ��ð������������һ��С����������Բ���ʲô������\n",
	    		]));
		}
		else message_vision("��¯�Ѿ��Ʋ����ˣ�\n", me);

	return 1;
}

int do_wedge(string arg)
{
 	object me=this_player();

	if( !arg || arg!="honghua ling" )
		return notify_fail("��Ҫ��ʲô����������¯��\n");

	if( me->is_busy() ) return notify_fail("����æ���ء�\n");
	else if ( get==1 && flag==1 && present("honghua ling", me) &&
			!(present("honghua ling", me))->query("zizhi") )
		{
			message_vision("$N���ŰѺ컨���������¯��\n",me);
			message_vision( HIR"ֻ����¯�����������죬�����Ǵ�����ʲô���ء�\n"NOR,me);
			me->start_busy(2);
			hit();
		}
		else 
		{
			if ( flag==0 )
				return notify_fail("��¯��������û�У�ʲô����Ҳ�岻��ȥ��\n");
			if ( !present("honghua ling", me) ||
				(present("honghua ling", me))->query("zizhi") )
				return notify_fail("�㲻�ܲ����ֶ�����ȥ��\n");
			if ( get==0 )
				return notify_fail("ѩ�����Ѿ����������ˣ�\n");
		}
	return 1;
}

void hit()
{
	object ob, me = this_player();

	message_vision("ͻȻֻ����ಡ���һ��������¯�������֧��������\n", me);
	if ( random( (int)me->query("kar") ) < 20 )
	{
		message_vision( HIR"$N��ǰһ������������������������Ķ���$N���ؿڡ�\n"NOR, me);
		me->unconcious();
	}
	else {
		message_vision( HIG"$N��æһ���������յıܿ��ˡ�\n"NOR,me );
		message_vision( HIG"��¯����ת����¶��һ��"NOR,me);
		message_vision( HIW"ѩ����"NOR,me);
		message_vision( HIG"��$N��æһ���������С�\n"NOR,me);
		ob = new(NOSTRUM_DIR"xuezhonglian" );
		me->start_busy(2);
 		ob->move(me);
     		ob = present("honghua ling", me);
		destruct(ob);
		get=0;
	}	
	return;
}
 
