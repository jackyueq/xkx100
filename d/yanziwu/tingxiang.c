//ROOM: /d/yanziwu/tingxiang.c

inherit ROOM;

void create()
{
	set("short", "����ˮ�");
	set("long",@LONG
�����ӻ������а˾ż�é��������������ӳ���������£������Ľ
�ݹ��ӵ��Ů�����ס���ˡ�
LONG );
	set("exits", ([
		"west" : __DIR__"biheqiao",
//		"south" : __DIR__"shuiyun",
	]));
	set("outdoors", "yanziwu");
	set("objects", ([
		__DIR__"obj/hualu1" : 1,
		__DIR__"obj/hualu2" : 1,
		__DIR__"obj/hualu3" : 1,
	]));
	set("coor/x", 860);
	set("coor/y", -1530);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
