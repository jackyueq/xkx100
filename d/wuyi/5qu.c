// Room: /d/wuyi/5qu.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������������ˣ����ϰ�����̨���˶����ұ��ϣ������ɼ�
����ʴ�����������̡�������ǵ���С�����еĵ�ʮ�����졣����
���������衷Ի������������ɽ���������ʱ���갵ƽ�֡��ּ��п�
����ʶ��������������ġ�������
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"north"     : __DIR__"yunwo",
		"south"     : __DIR__"yuchayuan",
		"southwest" : __DIR__"gengyitai",
		"northeast" : __DIR__"4qu",
		"northwest" : __DIR__"6qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1360);
	set("coor/y", -5020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

