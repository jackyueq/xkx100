// Room: /d/nanshaolin/huilang1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ƿ�������Ļ��ȡ�����������������Ҳ�ò�������˸��ַ�
���ͼ�Σ�ÿ�����ƺ�������˵һ���渶��˵ķ𾭹��¡�����������
���̵�������΢����ɳɳ���졣���ܾ����ĵģ�ֻ�����Լ��ĽŲ���
�ڶ��߻ص���
LONG );
	set("exits", ([
		"east"  : __DIR__"fatang",
                "west"  : __FILE__,
		"south" : __FILE__,
                "north" : __DIR__"huilang2",
	]));
	set("no_clean_up", 0);
	set("outdoors","nanshaolin");
	set("coor/x", 1810);
	set("coor/y", -6110);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

