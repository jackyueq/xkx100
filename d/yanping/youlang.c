// Room: /d/yanping/youlang.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "ʮ������");
	set("long", @LONG
ʮ�����ȴ�����ϪԴϿ���С����ȷ����������ɫ����������ʯ��
��������ʯ��ᾣ����·ת��ɽ��ˮ�أ�ǧ�����֣������������ľɭ
�������ٲ��ơ�
LONG );
	set("exits", ([
		"southeast" : __DIR__"beimenling",
		"northwest" : __DIR__"xiagu",
	]));
	set("outdoors", "yanping");
	set("no_clean_up", 0);
	set("coor/x", 1450);
	set("coor/y", -6150);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
