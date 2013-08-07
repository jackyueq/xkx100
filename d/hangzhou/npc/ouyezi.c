// ouyezi.c
#include <ansi.h>
#include <command.h>
inherit F_CLEAN_UP;
inherit NPC;

string *ouyezi_msg =({
GRN"ŷұ�ӽ�һ��"HIR"��ͭ"GRN"��һ��"HIC"����"GRN"������¯��������صķ��䣬����\n",
GRN"̰��������ͭ���顣..��ͭ����ͨ��͸"HIR"��"GRN"ʱ��ŷұ��ʦ����"BLK"����"GRN"����\n",
GRN"¯�У�����"HIY"�ƽ�"GRN"��"HIW"����"GRN"��һ�Ṥ��ŷұ���ø�ǯ�г����飬�͵�\n",
GRN"��������һ��������ζ��"BLK"��ɫҺ��"GRN"��..��..\n",
GRN"���..ƹ..ƹ..��....��....ƹ....ƹ...��....��...ƹ..��....��...ƹ...��.....\n",
GRN"..��....��....��....��....ŷұ�����쳤Ц�������壬������..��.....\n\n",
GRN"�����������ܴ�����ı�����ʲô��(name)��!\n"NOR,
});

void create()
{
        set_name("ŷұ��",({ "ou yezi","ou" }));
        set("gender", "����" );
        set("age", 73);
        set("long",
"ŷұ���ǵ���������ʦ�������Ľ������ޱȡ����������Ǯ̫�ٿ�Ҳ
���С�һ��Ǯһ�ֻ�ô��\n");
        set("combat_exp", 200000);
        set("attitude", "friendly");
        set("rank_info/respect", "ŷұʦ��");
        set("inquiry", ([
            "�콣": "�콣����˵��ʮ���ƽ𣬿������",
            "����": "�콣����˵��ʮ���ƽ𣬿������",
            "�۸�": "����۸���...!�ٺ�,һ��ʮ���ƽ���ۣ�һ��Ǯһ�ֻ�ô��",
         ]) );
        setup();
}
void init()
{
        object ob,me;
        add_action("do_name","name");
}
int accept_object(object me, object ob)
{
       if((int)me->query_temp("done_s",1))
       {
          say(
"ŷұ����ֵĿ���"+ me->query("name")+"����:�㲻�����Լ��ı�����\n");
        return 0; }
        if( ob->query("money_id") && ob->value() >= 100000)
        {
        command("nod");
        command("say �ð�,"+me->query("name")+"������������, ���Եȣ�\n");
        call_out( "ouyezi_stage", -10, me, 0 );
        (int)me->query_temp("marks/ouyezi");
        me->set_temp("marks/ouyezi",1);
        return 1;
        }
}
void ouyezi_stage(object ob, int stage)
{
        int i;
        object *inv;
        if( !ob || !present(ob) )
        return;
        tell_object(ob, ouyezi_msg[stage]);
        if( ++stage < sizeof(ouyezi_msg) ) {
        call_out( "ouyezi_stage", -10, ob, stage );
        return;}
}

int do_name(string arg,object ownsword)
{
        object me = this_player();
        if(!(int)me->query_temp("marks/ouyezi"))
        {
            return notify_fail("ŷұ������һ˦�֣�ʲô���������˼�Ҳ����\n");
        }
        if( !arg ) return notify_fail
         ("ŷұ���ʵ��������������ܴ�����ı�����ʲô��(name)��������(ask)�\n");
        if( strlen(arg) > 20 )
        return notify_fail("ŷұ��˵���ۿ�����ô����ôд���£������һ��İɣ�\n");

        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);

        ownsword= new(__DIR__"obj/ownsword");
        ownsword->set("name",arg +NOR);
        tell_object(me,
"ֻ��ŷұ��ʦ������㳦�����ڱ��������ֻ��������������"+arg+NOR"����\n");
        tell_object(me,
"���ɷ����ϸ�֣�ֱ���㿴��Ŀ�ɿڴ���\n\n");
        command("smile");
        command("say ���ˡ�" + me->query("name") +"����ȥ�ɣ�˵������һ�ѽ�
����..\n\n");
        ownsword->move(me);
        write("�����Ž�����һ�£��������Ƹ��������Ǿ�����˫�����ա�\n\n");
        (int)me->query_temp("done_s");
        me->set_temp("done_s",1);
        me->delete_temp("marks/ouyezi");
        return 1;
}

int do_ask(object me)
{
       me = this_player();
       if(!(int)me->query_temp("marks/ouyezi"))
       {
           return notify_fail("ŷұ�ӵ���������������\n");
       }
       write(@HELP
ŷұ��˵��:���������ս�������( name <����> ),
�����ڱ����Ͽ��֣������������ı����Ͽ��´�ɫ���֣���������ô��
�Ǿ�Ҫ����ĳ�����⹤�գ�������������˵��:

$BLK$ - ��ɫ            $NOR$ - �ָ�������ɫ
$RED$ - ��ɫ            $HIR$ - ����ɫ
$GRN$ - ��ɫ            $HIG$ - ����ɫ
$YEL$ - ����ɫ          $HIY$ - ��ɫ
$BLU$ - ����ɫ          $HIB$ - ��ɫ
$MAG$ - ǳ��ɫ          $HIM$ - �ۺ�ɫ
$CYN$ - ����ɫ          $HIC$ - ����ɫ
$WHT$ - ǳ��ɫ          $HIW$ - ��ɫ

�ҵ�����������ɫ��
HELP
        );
        return 1;
}
