// Room: /d/jiaxing/yangjia.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ�������Ѿõ��񷿣��Ҿ߰���һӦ��ȫ��ֻ�Ƕ�����һ���
���������м���һ��С�������ϵı��뻹��û�г�ȥ����������ȥ�ĺ�
��æ��ǽ�Ϲ���һ����ǹ��
LONG
	);
	set("item_desc", ([
		"qiang" :  "һ���þ��˵���ǹ��������ԭ��Ӧ����һ�Եģ���֪Ϊ��ֻʣ��һ�ˡ�",
		"tieqiang" : "һ���þ��˵���ǹ��������ԭ��Ӧ����һ�Եģ���֪Ϊ��ֻʣ��һ�ˡ�",
	]) );
	set("exits", ([
		"south" : __DIR__"njroad3",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1580);
	set("coor/y", -1040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}