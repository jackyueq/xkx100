// Room: /d/taishan/weiping.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "Χ��ɽ");
	set("long", @LONG
����̩ɽ������һ��ɽ�壬������ʯ�塣ɽ�Ķ�����һ����ͷ�£�
����״����һͷ�����������бܷ��£����ϴ��ؿ��š����¸ԡ�����
�����档���ϸ���Ϊ�����壬���⡰����ʯ�������嶫Ϊ�廨�£��׺�
���˷塣��ʱ��������·���Ƿ��ӵ��������������ϡ��嶥��ʯ������
�ϣ�������ʯ���ɴ���ɽ�ߵ�֮���ĳ��򲻶���������ҡ�����µס���
�����б���̳�������������ߣ���ɵ����ŷ�̩ɽ֮���ϼԪ���ı�ϼ
����
LONG );
	set("exits", ([
		"westdown" : __DIR__"tianjie",
		"eastdown" : __DIR__"bixia",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 380);
	set("coor/y", 770);
	set("coor/z", 220);
	setup();
	replace_program(ROOM);
}
