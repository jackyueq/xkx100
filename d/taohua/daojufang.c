inherit ROOM;

void create()
{
	set("short", "���߷�");
	set("long", @LONG
����һ����߷�������һЩ�һ������ǳ��õĶ�������������
�����ģ���������һ�Ű߲�������һ�ѿ����Σ����ǰ��컹����С��
�ơ����Ϳ������������ʹ�������㣬��Ȼ�ڲ����ԣ����㻹������
�㷡�
LONG );
	set("exits", ([
		"south" : __DIR__"zoulang3",
	]));
	set("objects", ([
		__DIR__"obj/xiang" : 1,
	]) );
	set("coor/x", 8990);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}