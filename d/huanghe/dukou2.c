// Room: /d/huanghe/dukou2.c
// Last Modified by winder on Apr. 10 2000
#include <ansi.h>
inherit RIVER;

void create()
{
	::create();
    set("short", "���Ŷɿ�");
    set("long", @LONG
�ɿ�ǰ������ӿ���ȵĻƺ�(he)�ˡ�������������ɳ���£�������
������ɴ������������ڲ����д��У���Ϊ���ա����˻ƺӣ������
��ɽ���ˡ�
LONG );
    set("exits", ([
        "southwest" : "/d/huanghe/weifen",
    ]));
    set("item_desc", ([
        "he" : "һҶС��ҡ�ڲ����ض���ǰ�У���(yell)һ���Կ���\n",
    ]));
    set("no_clean_up", 0);
    set("outdoors", "heimuya");
	set("coor/x", -1500);
	set("coor/y", 2000);
	set("coor/z", 0);
  set("yell_about", "����");             // yell ����
  set("river_type", "��");               // �����ϴ�������
  set("need_dodge",300);                 // ��Ҫ�����Ṧ
  set("come_msg_out",   "һҶ���ۻ�����ʻ�˹�����������һ��̤�Ű���ϵ̰����Ա�˿����¡�\n");
  set("busy_msg",       "ֻ���÷�������������������������æ���š�����\n");
  set("wait_msg",       "����һֻ�ɴ��ϵ�������˵�������������أ������ɡ�\n");
  set("leave_msg_out",  "������̤�Ű��������������һ�㣬��������г�ȥ��\n");
  set("leave_msg_in",   "������̤�Ű���������˵��һ��������ඡ������һ�㣬��������г�ȥ��\n");
  set("come_msg_in",    "����˵���������ϰ��ɡ����漴��һ��̤�Ű���ϵ̰���\n");
  set("item_desc/river", HIC "\nֻ��һҶС��ҡ�ڲ����ض���ǰ�У�Ҳ�������("
                         HIY "yell" HIC ")һ������(" HIY "boat" HIC
                        ")��\n���������������Ը��Ṧ����,Ҳ��ֱ��"
                        "��ˮ(" HIY "cross" HIC ")̤�Ӷ�����\n" NOR);
  set("boat_short", "�ɴ�");    
  set("boat_desc",  @LONG
�ƺ��ϵ�С�۶������ֺܼ�ª��С�ۡ�һλ����������վ�ڴ�β
�������ƶ棬һλ����׳˶��С����Ҳ�ڴ�ͷ�þ��ػ�ˮ�Ŵ����ƺ�
ˮ���ļ������»��ܿ죬���ȴ������
LONG );
  set("to",         "/d/heimuya/dukou1");  // �����յ� /*   ��ѡ   */
	setup();
}
