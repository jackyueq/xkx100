// Room: /qingcheng/xiaoqiao.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "С��");
	set("long", @LONG
С�ź��СϪ�ϡ�Ϫˮ�峺��������ʯ�߲��������ű������
��ǽ������ˡ�����ǵ��ҷ���֮�����ŵ��̵ġ����嶴�족����
�����������ڴ˽�®�����嶷�׵������������࣬�����÷�������
LONG );
        set("outdoors","qingcheng");
	set("exits", ([
		"south" : __DIR__"qcroad3",
		"north" : __DIR__"jianfugong",
	]));

        set("no_clean_up", 0);
	set("coor/x", -8060);
	set("coor/y", -930);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}