// Room: /d/heimuya/neishi.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "С������");
	set("long", @LONG
������С�����ҡ���ʰ�þ�ϸ�쳣����һ��ȥ���ͷ��ִ�������һ
��������޵��ˡ�����Ҳ�����̧ͷ���㷢������Ȼ�Ǹ����ˣ�����ִ
��һö�廨�룡
LONG    );
	set("exits", ([
		"west" : __DIR__"xiaoshe",
	]));
	set("objects", ([
		CLASS_D("heimuya")+"/dongfang": 1,
	]));
	set("coor/x", -3240);
	set("coor/y", 4220);
	set("coor/z", 100);
	setup();
}
