// Room: /d/yueyang/banzhu1.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һƬ�����֡����紵����һ��Ҷ�졣�����ֽ������񣬽���
�ʡ�����־�����أ���Ң֮��Ů��˴֮������Ի��������ˡ����۱���
�����䣬��������񾡰ߡ�����������־���أ�����ɽ�����񡱡���
���Ө������ϵ����������ɫ�ߵ㣬ʩ���ᡶ����ʡ��ƣ������
�潭��������Թ�Σ����곤����ֻ����۶ࡱ��
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"banzhu2",
		"west"  : __DIR__"banzhu3",
		"south" : __DIR__"banzhu1",
		"north" : __DIR__"erfeimu",
	]));
	set("coor/x", -1670);
	set("coor/y", 2290);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
