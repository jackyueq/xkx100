// wg_lang6.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǹ����ȣ�����ͨ����Ϣ�ң���������Ʒ�������ﾲ���ĵģ���
����·��ҲС������ģ��³��Ŷ�����Ϣ������Ϣ���ˡ�
LONG);
	set("exits", ([
		"east" : __DIR__"wg_woshi1",
		"west" : __DIR__"wg_wupinfang",
	]));
	set("outdoors", "wuguan");
	set("coor/x", 51);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

