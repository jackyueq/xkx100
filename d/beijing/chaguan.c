// Room: /beijing/chaguan.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ�����Ű���
��һ���ſ��������˿��ˣ������̸Ц����ͷ�Ӷ�����Ҫ���������
�ƹʺ�ҥ�ԣ������Ǹ������ڡ�
LONG );
	set("resource/water", 1);
	set("exits", ([
		"west" : __DIR__"nandaj2",
	]));
	set("objects", ([
		CLASS_D("yunlong")+"/guanfuzi" : 1,
	]));
	set("coor/x", -190);
	set("coor/y", 4020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
