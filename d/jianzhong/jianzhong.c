#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","��ڣ");
	set("long",@LONG
ƽ̨�ϴ�ʯ����ڣ����������֮�ԣ��������������С��ʯ�̣�
        ����ħ������ܼ��޵������£�������˹��
          �غ���Ⱥ�����֣��������������౯�򣡡�
��ʯ֮�£����ʯ�����һ����أ�����ɽ�ȣ�����������ռ����
���ơ��뽣ħ����ȫ�ţ������ǳ��������������ˣ���Ե�ü���λ
ǰ��Ӣ�ۣ��㲻�����쳤̾��������ǧ��
LONG
	);
	set("no_clean_up",1);
	set("move_stone",1);
	set("outdoors", "jianzhong");
	set("coor/x", -401);
	set("coor/y", -421);
	set("coor/z", 50);
	setup();
}
void init()
{
	add_action("do_move","move");
	add_action("do_move","ban");
	add_action("do_climb","climb");
}
int do_move(string arg)
{
	object me,room,ob,ob1,ob2,ob3;
	me=this_player();
	room=this_object();
	if((arg!="stone")&&(arg!="ʯ��"))
	{	
		return notify_fail("��Ҫ��ʲô��\n");
	}	else	
	{
		if(!room->query("move_stone"))
			return notify_fail("ʯ���ѱ��˰Ὺ�ˣ�\n");
		message_vision("$N�Ὺ��ڣ�ϵ�ʯ�飬¶���˲��е������������ڵ�һ�����ѳ���\n֮�䣬����һ�鳤ʯ��Ƭ�����ѽ���ʯƬ������һ�����ʯ֮�ϡ�\n",me);
		room->set("move_stone",0);
		ob=new(WEAPON_DIR"treasure/qingguang-jian");
		if ( ob->violate_unique() ) destruct( ob );
		else ob->move(room);
		ob1=new("/clone/book/shipian");
		if ( ob1->violate_unique() ) destruct( ob1 );
		else ob1->move(room);
		ob2=new(WEAPON_DIR"treasure/xuantie-jian");
		if ( ob2->violate_unique() ) destruct( ob2 );
		else ob2->move(room);
		ob3=new(__DIR__"obj/mujian");
		ob3->move(room);
	}	
	return 1;
}
int do_climb(string arg)
{
	object me;
	me=this_player();
	if(arg!="down")	return notify_fail("��Ҫ���Ķ�����\n");
	message_vision("$N˳����·������ȥ��\n",me);
	me->move(__DIR__"qiaobi");
	message_vision("$N�ӡ���ڣ��������������\n",me);
	return 1;
}
