// Room: /d/taishan/tianshen.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��ĸ�����в�Զ�������ɽ��ɽ·Խ��Խ�������ˡ�����ǰ��ʯ��
��磬��עˮ���š�������Σ������������ɢ�飬����������������ң�
�׳�ˮ�������Ҷ�ɽ�걱�����������ʡ��ֹŶȡ���Ω�����˼��˺���
��ˮ��ʫ��Ħ�̡������Ҷ�����Ⱥʯ����������̡����˳��족����
����������۶��ء�
LONG );
	set("exits", ([
		"north"     : __DIR__"dengxian",
		"southdown" : __DIR__"doumo",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 400);
	set("coor/y", 610);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}
