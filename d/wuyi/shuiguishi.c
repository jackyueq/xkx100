// Room: /d/wuyi/shuiguishi.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "ˮ��ʯ");
	set("long", @LONG
�������ǣ��������ص�����ʯ��������ص���̬�ͱ������״����
һ������ˮ����Ϸ��������չ�����쾡�£�һֻǱ��ˮ�ֻ¶���Դ�
�ͼ�������һֻ�������ļ����ϣ���ˮ����������Ĳ�����������ʶ��
ʯ���ڶ����������ɶ������˾�̾�ƾ���
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northwest" : __DIR__"7qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1350);
	set("coor/y", -5020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

