// Room: /d/chengdu/caotang.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "�Ÿ�����");
	set("long", @LONG
�����ǶŸ���Ԣ�ɶ��Ĺʾӡ���������ˮ���ӣ�С�Ź���������
��ӳ���Եü�ׯ�����£����ӵ��ţ��ֲ�ʧ����ף��������ʡ�
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
		"south" : __DIR__"baihuatan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8090);
	set("coor/y", -2970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
