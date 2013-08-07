// Room: /yixing/taihu.c
// Date: Nov.18 1998 by Winder

#include <ansi.h>
inherit RIVER;

void create()
{
	::create();
	set("short", "̫��");
	set("long", @LONG
̫���ų������������ݣ�������������֮ˮ�Թ��ڴˡ���ʱ
���������޲������۽Ա̣���ʮ����Դ�ͦ����������ǧ�겨��֮�У�
���������Ļ��󳩡��ɴ˵Ǵ���ǰ��̫��֮�еĹ���ׯ��
LONG );
	set("outdoors", "yixing");
	set("exits", ([
		"north" : __DIR__"shanlu1",
	]));
	set("objects", ([
		"/d/guiyun/npc/xiaolu" : 1,
	]));
	set("item_desc", ([
		"hu"  : HIC "\n�����ϴ���һҶС�ۣ�����һ�����ҹ����ڻ�����Ҳ�������("
            HIY "yell" HIC ")һ����\n��(" HIY "boat" HIC
            ")�����������������Ը��Ṧ����,Ҳ��ֱ��"
            "��ˮ(" HIY "cross" HIC ")̤ˮ������\n" NOR,
	]));
	set("coor/x", 230);
	set("coor/y", -190);
	set("coor/z", 0);
  set("yell_about", "����");             // yell ����
  set("river_type", "��");               // �����ϴ�������
  set("need_dodge",300);                 // ��Ҫ�����Ṧ
  set("come_msg_out",   "һҶ���ۻ�����ʻ�˹�����������һ��̤�Ű���ϵ̰����Ա�˿����¡�\n");
  set("busy_msg",       "ֻ���ú�������������������������æ���š�����\n");
  set("wait_msg",       "����һֻ�ɴ��ϵ�������˵�������������أ������ɡ�\n");
  set("leave_msg_out",  "������̤�Ű��������������һ�㣬���������ʻȥ��\n");
  set("leave_msg_in",   "������̤�Ű���������˵��һ��������ඡ������һ�㣬���������ʻȥ��\n");
  set("come_msg_in",    "����˵���������ϰ��ɡ����漴��һ��̤�Ű���ϵ̰���\n");
  set("item_desc/river", HIC "\n�����ϴ���һҶС�ۣ�����һ�����ҹ����ڻ�����Ҳ�������("
                         HIY "yell" HIC ")һ����\n��(" HIY "boat" HIC
                         ")�����������������Ը��Ṧ����,Ҳ��ֱ��"
                        "��ˮ(" HIY "cross" HIC ")̤ˮ������\n" NOR );
  set("boat_short", "�ɴ�");    
  set("boat_desc",  @LONG
�밶��Զ����������������Ī֪���֮�ں������ֻ��Ǻ���֮����
�ء����ҹ��ڴ�β���еػ���ˮ��
LONG );                                   // �ɴ��ϵ�����
  set("to",         "/d/guiyun/matou");  // �����յ� /*   ��ѡ   */
	setup();
}