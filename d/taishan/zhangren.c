// Room: /d/taishan/zhangren.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "���˷�");
	set("long", @LONG
����λ����ʶ���������ĵط�����״����һ�����͵����ˡ�����
�����鿡��Сʯ�������С�����Ū�֮�ơ������С����µ�һɽ����
�����������������������������������һ��������̣�����Ǭ¡ʫ��
����������������ǣ�᷶������ٽ�����ȴ������֪�˹ߣ�˭����Ͼ�
��������
    �����лƻ�������·��ΪΣ�գ������ڽ�·��д�ϡ��س��ҡ���
�����������߱���᷶��ı����š�
LONG );
	set("exits", ([
		"southeast" : __DIR__"yuhuang",
		"northup"   : __DIR__"beitian",
	]));
	set("objects",([
		__DIR__"npc/wei-shi1" : 2,
	]));
	set("outdoors", "taishan");
	set("coor/x", 350);
	set("coor/y", 790);
	set("coor/z", 210);
	setup();
	replace_program(ROOM);
}
