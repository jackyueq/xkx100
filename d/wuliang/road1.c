// Room: /wuliang/road1.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
�����ǽ������ڵ�����ǰͨ���ţ��������������ڴ����ʹ���
���Ϊ����֮��ÿ�����꣬�������µ��ӱ��ڽ������б��䶷����
��ʤ��һ�ڵ��ڽ�������ס���꣬�������������б��ԡ��峡������
Ӯ��������Ϊʤ�����ڱ����ϵ�ش��������Է����Ժ��һֱ����
������
LONG );
        set("outdoors", "wuliang");
	set("no_clean_up", 0);
        set("valid_startroom", 1);
	set("exits", ([
		"out"     : __DIR__"jianhugate",
		"northup" : __DIR__"zhengting",
	]));
	set("coor/x", -71000);
	set("coor/y", -79900);
	set("coor/z", 90);
	setup();
        "/clone/board/wuliang_b"->foo();
}