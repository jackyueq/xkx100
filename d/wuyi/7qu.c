// Room: /d/wuyi/7qu.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǹ����ϣ��߸߿��š�����̶���������֡�����Ϫ֮������
����ˮ���������黶�ã�������������̶�ľ��Ѳ��޹�ϵ��������
���������������Ѳ�������һ��Ħ��ʯ���ˡ����䡶�������衷Ի��
���������������ϱ�̲���������Ƹ��ؿ���ȴ����ҹ��ͷ�꣬��÷�
Ȫ��������������
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"6qu",
		"north"     : __DIR__"path7",
		"southwest" : __DIR__"8qu",
		"southeast" : __DIR__"shuiguishi",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1340);
	set("coor/y", -5010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

