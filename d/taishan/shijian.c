// Room: /d/taishan/shijian.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "�Խ�ʯ");
	set("long", @LONG
���������о�ʯ����Լ���ɣ�������ɣ�ʯ��Ϊ���룬���⡰�Խ�
ʯ�����֣�������Ͽʯ��������¡�����������ʯͤ��������������
��кһ���꣬��ʯ���ǧ���ġ�����Ħ�̡���ɽ��ˮͤ�ǡ����������
��Ӧ��Ħ�̲��顶ɹ��ʯˮ��ʫ������ɹ��ʯ��ˮ��Ȫ��˭���������
�졣���¿ع������񣬳��紵��ĺ���̡�������ĭ�ɻ�ʪ���������ƶ�
������ѡʤ��������ͣ���ʫ�������紪����
LONG );
	set("exits", ([
		"southeast" : __DIR__"jingshi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 400);
	set("coor/y", 610);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}
