// Room: /d/lingxiao/didi.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "�ص�");
	set("long", @LONG 
���ﰴ���ƶ��ԣ���������صף������ѩɽ��ɽ��֮���ˡ�����
���س�ʪ��������һ��ŨŨ������ζ��ǽ����Ȼ���ż�֧��ѣ��յ���
�������õġ�һ���������������龯��Ľ�ʿ��������һ�Ⱦ޴��ʯ��
��men���ԡ�
LONG );
	set("exits", ([
		"up" : __DIR__"laolang",
	]));
	set("objects", ([ 
		__DIR__"npc/shi" : 1,
	])); 
	set("item_desc", ([
		"men" : "һ�Ⱥ���ʯ��,����ǧ��֮�أ�ʹ�����ƣ�push������֪���᲻�Ὺ��\n"
	]) );
	set("coor/x", -30990);
	set("coor/y", -8900);
	set("coor/z", 120);
	setup(); 
}

void init()
{
	add_action("do_push", "push");
}
int do_push(string arg)
{
	object me=this_player();

	message_vision("$N��������������������һ�����˾���ʯ����ȥ��\n",me);
	if (me->query("max_neili") < 500)
	{
		message_vision("$N���˸�������ʯ��ȴ��˿������\n",me);
		return 1;
	}
	message_vision("ֻ��������Ŧ����֮��������ʯ�ž��������ˡ�\n",me);
	set("exits/enter",__DIR__"dilao");
	remove_call_out("close");
	call_out("close", 5, this_object());
	return 1;
}
void close_out()
{
	if (query("exits/enter")) delete("exits/enter");
}

void close(object room)
{
	message("vision","�������˴��һ����С���˵����㲻�������͸�үү���ɣ��������䣬һ�󾢷������ʯ�ű����һ�¹��ˡ�\n", room);
	room->delete("exits/enter");
}

