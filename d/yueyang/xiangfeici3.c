// Room: /d/yueyang/xiangfeici3.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
�����Ϸ���������һ��ڵ׽����ң����顰Ԩ�º����Ϊ�ഫ��
��ŮӢ��ˮ�󣬱���۷���Ϊ��Ԩ�º󡱣�����֮���޸�������ʱ����
��������Ϊ��Ԩ�º�����д��ҡ��߽�����������ƣ������̨��
�����ж�������������Ů�ܷ������ԡ���������˽�����������չ�
��ȥʱ�����Ц�ݣ����ǣ����˼��꣬����������Ц��ת��Ϊ���ຬ
�����顣������ζ˭ʶ��
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"xiangfeici2",
	]));
	set("coor/x", -1660);
	set("coor/y", 2330);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
