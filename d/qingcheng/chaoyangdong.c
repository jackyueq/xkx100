// Room: /qingcheng/chaoyangdong.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
����������������������ɣ��ഫ����������Ϣ��������Ҳ��
���պ�ȥ�������Ŷ����ٹ���ҫ��������ָ���ն�����ϼ��͸����
���䵽���ڣ�һƬ譲�Ѥ���ľ�ɫ��
LONG );
        set("outdoors","qingcheng");
	set("exits", ([
		"westdown"  : __DIR__"zushidian",
		"northup"   : __DIR__"sanwanjiudao",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -8090);
	set("coor/y", -890);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}