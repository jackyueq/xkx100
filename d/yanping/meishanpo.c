// Room: /d/yanping/meishanpo.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "÷ɽ��");
	set("long", @LONG
÷ɽ���ϱ�ֲ÷��������ӯҰ��һ������������Ⱥ�����ţ�����
�ش����糯�����������ޱߡ���÷ɽ���͡�λ����ƽ�˾�֮һ����
��������������ɧ�ͣ��ӽ����ƣ�����ʱ��
LONG );
	set("exits", ([
		"westup"   : __DIR__"zhouxue",
		"northup"  : __DIR__"beimenling",
		"eastdown" : __DIR__"dongmen",
	]));
	set("outdoors", "yanping");
	set("no_clean_up", 0);
	set("coor/x", 1480);
	set("coor/y", -6170);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
