// Room: /d/wuyi/tongxianjing.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "ͨ�ɾ�");
	set("long", @LONG
ͨ�ɾ�λ������԰�ڣ���������Ȫ����ˮ��������Ϊ�Ʋ���ϵ�
��ˮ���ų�����ɽ��һ����ʫԻ����ʯ��մ�����Ƹ�ʯ��������걸�
���������˶����Ρ���
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"yuchayuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1390);
	set("coor/y", -5020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

