// Room: /qingcheng/sanwanjiudao.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "����ŵ�");
	set("long", @LONG
ɽ��Խ��Խ���ͣ�ʯ�ݼ����������չ�����ͤ��ԶԶ�������
ɽ�ۣ���̨ɽ֮���ķ������ߣ����幬���ˡ�
LONG );
        set("outdoors","qingcheng");
	set("exits", ([
		"southdown"  : __DIR__"chaoyangdong",
		"eastup"    : __DIR__"shangqing",
	]));
	set("objects", ([
		CLASS_D("qingcheng")+"/first" : 1,
	]));
	set("coor/x", -8090);
	set("coor/y", -880);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}