// Room: /d/huanggong/junjichu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ�Ų����۵ķ���. �������ְ���С�ķ�����ʵ��ͬѰ��, 
���Ǹ����ʵ۵�����������, �Դ�����������Ϊ�����������, ��
�����������.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"southeast" : __DIR__"qianqingmen",
	]));
	set("no_clean_up", 0);

	set("coor/x", -210);
	set("coor/y", 5290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}