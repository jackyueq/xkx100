// d/meizhuang/huashi.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǵ������Ļ��ң��׻�˵���黭���ּң����Ե��������鷨Ҳ
���൱�Ĺ�������Ȼ����������ͺ���̺ܶ࣬���������Ľ�����������
�鷨���У�Ҳ��ν�����������ˡ�����ĳ�������Ҳ�࣬Ψһ��ͬ
���������ǽ�ϲ�û�йҵ������ĵ�����ʣ����ǹ������ǰ�����ҵ�
���������ڵ������Լ�����һ��д�š������С������á�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"zoulang1",
	]));
	set("objects", ([ /* sizeof() == 1 */
		CLASS_D("heimuya")+"/sheng.c" : 1,
	]));

	set("coor/x", 3510);
	set("coor/y", -1380);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
