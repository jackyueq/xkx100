// Room: /d/taishan/xiayi.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ƿ���̨��ߵ�������������������ʹ��ƽʱ����ɽʱ��
ͨ������������������ֹ������������з��Ű�̫ʦ�Σ�����ʹ��
���������濪���������Ҹ������ż�λ������ʿ������ȥ������
�ݣ�����һ��ׯ������
LONG );
	set("exits", ([
		"west" : __DIR__"fengchan",
	]));
	set("objects",([
		"/clone/npc/shang-shan" : 1,
		__DIR__"npc/wei-shi2" : 3,
	]));
	set("coor/x", 420);
	set("coor/y", 630);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
