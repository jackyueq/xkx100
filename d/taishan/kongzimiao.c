// Room: /d/taishan/kongzimiao.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������λ�ڿ������£����ξ����������⽨������ɽ�š����
���ڷ���ӣ��������ӡ����ӡ���˼�����ӵȡ�ɽ��������������
������������֮�ָߣ���֮�ּᣬ��������Ҳ���������࣬�κ����ͣ�
��������Ȼ����
LONG );
	set("exits", ([
		"southup" : __DIR__"kongziya",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 370);
	set("coor/y", 790);
	set("coor/z", 210);
	setup();
	replace_program(ROOM);
}
