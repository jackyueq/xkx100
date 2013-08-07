// Room: /d/taohua/jingshe.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;
int do_pai(string arg);

void create()
{
	set("short","����");
	set("long",@LONG
�����һ�������ҩʦ���鷿��ȫ���Բ���Ƥ��������ɣ���������
�����١������������ģ�һ����������ӣ�����ͻ��һ��������������
��ʫ���伮�������档�ݱ߰���һ������(zhuozi)�������ǽ���Ϲ���
һ����īɽˮ��
LONG
	);
	set("exits",([
		"south" : __DIR__"dating",
	]) );
	set("no_clean_up",0);
	set("item_desc",([
		"table" : "����һ��ʯ����\n",
		"zhuozi" : "����һ��ʯ����\n",
	]) );
	set("coor/x", 9010);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_pai", "pai");
	add_action("do_pai", "press");
}

void close_door(object room)
{
	message("vision", "�����Զ�����������ס����ڡ�\n", room);
	room->delete("exits/enter");
}

int do_pai(string arg)
{
	object me = this_player();

	if (me->is_busy() || me->is_fighting())	return notify_fail("����æ���أ�\n");
	if( arg == "table" || arg == "zhuozi")
        {
		write("������Ϲ��ŵĵ�īɽˮ������������¶��һ����������\n");
		set("exits/enter", __DIR__"liandanfang");
		remove_call_out("close_door");
		call_out("close_door", 5, this_object());

                return 1;
        }
}