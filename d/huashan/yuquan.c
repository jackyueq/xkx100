// yuquan.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "��ȪԺ");
	set("long", @LONG
�������ݺ����Ȫ�����������δ���ϣ�����ӵĵط�����Χ����ʮ
��������٣�ز�ö��ˣ�֦���пգ�����������ƣ��ഫ��ϣ��������
��������ֲ��Ժ��������գ�Ȫʯ�续����ˮ�ӻأ��������ۡ�Ժ����
��Ȫһ�ɣ�Ȫˮ����������ɽ������������ͨ��������Ȫ����ȪԺ��
�˵�����
LONG );
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"path1",
	]));
	set("objects", ([
		__DIR__"npc/teller": 1
	]) );
	set("outdoors", "huashan");

	set("coor/x", -920);
	set("coor/y", 280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
 
