// Room: /d/guiyun/kefang.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short","�ͷ�");
	set("long",@LONG
���ǹ���ׯ�д�����ס�޵ķ��䡣���ڳ��辫�ţ�������ԣ�����
�Žࡣ���洰����һ����԰�����Ͼ��£��������С�
LONG
);
	set("exits",([
		"south" : __DIR__"zoulang2",
	]) );
	set("no_clean_up", 0);
	set("sleep_room", 1);
	setup();
	replace_program(ROOM);
}
