// Room: /d/wuyi/yunvfeng.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "��Ů��");
	set("long", @LONG
��Ů��ͤͤ����Ů������ͻأͦ�Ρ��嶥���ܲδأ���ľ�Դ����Σ�
ǡ��ɽ�����ޡ��ұ�����⻬��������������������Ϫ�ϣ���Ȼ����
�ַ�����·�ʵǡ����廨��ˮһ��壬��Ǳ�����Ů�ݡ�����д�ա���
��ԡ��̶��Ϊ��Ů��ԡ�����嶫Բʯ�羵����Ϊ��ױ̨��
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"2qu",
		"southeast" : __DIR__"jingtai",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1380);
	set("coor/y", -5010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

