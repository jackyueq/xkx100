// Room: /d/nanshaolin/bydian.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "���µ�");
	set("long", @LONG
���ǰ��µ������¹�����ʿ����ʿ�߾��������ϣ����о�ƿ��
ü��΢�����ǳЦ���·���˼伲��ȴ����ģ��־��ͻ������з���
��ľ���㰸���㰸�Ϲ�Ʒ�뱸�����ʮ����ʢ��
LONG );
	set("exits", ([
		"west" : __DIR__"kchang",
	]));
	set("no_clean_up", 0);
	set("outdoors","nanshaolin");
	set("coor/x", 1830);
	set("coor/y", -6100);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}



