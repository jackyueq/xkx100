// Room: /d/yanping/jiusi.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�Ƶ��ſ�һ�������Ӱ����ӹ��ţ��������ϲ�ȴ�����ˡ�����é��
��С���Ե�ʮ�ֿ��䣬ֻ��һ���������Ẻ�ӿ��ھ�¯�ϣ�һ˫�۾���
��������㡣
LONG );
	set("exits", ([
		"south"     : __DIR__"guandao1",
	]));
        set("objects", ([
		"/d/qingcheng/npc/yuyan" : 1,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1700);
	set("coor/y", -6290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
