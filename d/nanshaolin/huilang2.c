// Room: /d/nanshaolin/huilang2.c
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
		"west"  : __DIR__"huilang3",
                "east"  : __FILE__,
		"north" : __FILE__,
                "south" : __DIR__"huilang1",
	]));
	set("no_clean_up", 0);
	set("outdoors","nanshaolin");
	set("coor/x", 1810);
	set("coor/y", -6100);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

