// Room: /d/suzhou/jubaozhai.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "�۱�ի");
	set("long", @LONG
����һ�����ֺ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ
�����е���Ʊ�����ǳ��ã�ͨ��ȫ����
    �ڶ����ǽ�Ϲ��˿�����(paizi)��
LONG );
//	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("item_desc", ([
		"paizi" : @TEXT
     ��Ǯׯ�ṩ���·���
      ��Ǯ        deposit����cun
      ȡǮ        withdraw����qu
      Ǯ�Ҷһ�    convert����duihuan
      ����        check����chazhang
TEXT
	]) );
	set("exits", ([
		"east"  : __DIR__"nandajie1",
	]));
	set("objects", ([
		__DIR__"npc/sun": 1,
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_beg", 1);
	set("coor/x", 840);
	set("coor/y", -1030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
