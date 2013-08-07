// yanlian.c

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }
int practicing(object me);
int halt_practice(object me);

int main(object me, string arg)
{
	seteuid(getuid());

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if (environment(me)->query("no_fight"))
                return notify_fail("������������Ҳ���³������ˣ�\n");

        if (! arg)
                return notify_fail("��������ʲô��\n");

        if (file_size(SKILL_D(arg) + ".c") <= 0)
                return notify_fail("û��˵���������书��\n");
               
        if (! mapp(SKILL_D(arg)->query_sub_skills()))
                return notify_fail("�����书���������������ڼ���ϰ�ɡ�\n");

        if ((int) me->query_skill(arg, 1) > 0)
                return notify_fail("���Ѿ���" + to_chinese(arg) +
                                   "�ˣ������������ˣ����Ƕ���ϰ�ɡ�\n");

        if (! SKILL_D(arg)->get_ready(me))
                return 1;

        me->set_temp("pending/practice", 1);
        me->set_temp("pending/practicing_skill", arg);
	me->start_busy((: practicing :), (: halt_practice :));

        write("�㿪ʼ����" + to_chinese(arg) + "��\n");
        return 1;
}

int practicing(object me)
{
        int i;
        int lvl;
        int step;
        int cost;
        string skill;
        string sub_skill;
        string action_msg;
        mapping action;
        mapping sub_skills;
        string  *skill_names;
        string  *color_msg = ({HIY, HIG, HIW, HIM, HIC});

        step = (int) me->query_temp("pending/practice");
        skill = me->query_temp("pending/practicing_skill");
        if (! step || ! stringp(skill))
                return 0;
        if (! mapp(sub_skills = SKILL_D(skill)->query_sub_skills()))
                return 0;

        skill_names = keys(sub_skills);
        if (step <= sizeof(sub_skills))
        {
        	
                sub_skill = skill_names[step - 1];
                if (! me->query_skill(sub_skill, 1))
                {
                        write("����������������ͻȻһ�㣬��ŷ����Լ���������" +
                              to_chinese(sub_skill) + "��\n");
                        return 0;
                }
                if (file_size(SKILL_D(sub_skill) + ".c") <= 0)
                {
                        write("�š���ô���£���ô" + to_chinese(sub_skill) +
                              "�����书����ʧ���ˣ�\n");
                        return 0;
                }
                action = SKILL_D(sub_skill)->query_action(me, me->query_temp("weapon"));
                action_msg = action["action"];
                action_msg = replace_string(action_msg, "$n", "���");
                action_msg = replace_string(action_msg, "$l", "�޾���");
                action_msg = replace_string(action_msg, "$w", "����");
                cost = action["force"] * 8 / sizeof(sub_skills);
                if (me->query("neili") < cost)
                {
                        write("��������У���Ȼ�䵤���������̣�����ʩΪ��\n");
                        return 0;
                }
                me->add("neili", -cost);
                cost = action["force"] / 10;
                if (me->query("qi") < cost)
                {
                        write("������������ӣ�ƣ���������޷��ٳ��С�\n");
                        return 0;
                }
                me->add("qi", -cost);
                cost = action["force"] * 8 / me->query("int") / sizeof(sub_skills);
                if (me->query("jing") < cost)
                {
                        write("һ�󷳶�ӿ����ͷ���㼸��Ż�¡�\n");
                        return 0;
                }
                me->add("jing", -cost);

                message_vision(/*color_msg[random(sizeof(color_msg))] +*/ action_msg +
                               "��\n\n" NOR, me);
                if (me->query_skill(sub_skill, 1) <
                    (int) sub_skills[sub_skill])
                {
                        write("��������" + to_chinese(sub_skill) + "��һ�У�"
                              "������Щ��ã��һʱ�޷�����������ȥ��\n");
                        return 0;
                }
        } else
        {
                message_vision("$N��������ס������������˼��\n", me);
                me->set_temp("pending/practice", 0);
                if (SKILL_D(skill)->get_finish(me))
                {
                        write(HIC "\n��ϲ�������ˡ�" + to_chinese(skill) + "����\n\n" NOR);
                        lvl = 0;
                        for (i = 0; i < sizeof(sub_skills); i++)
                        {
                                lvl += me->query_skill(skill_names[i], 1);
                                me->delete_skill(skill_names[i]);
                        }
                        lvl /= sizeof(sub_skills);
                        me->set_skill(skill, lvl);
                }
                return 0;
        }

        step++;
        me->set_temp("pending/practice", step);
        return 1;
}

int halt_practice(object me)
{
        write("����ס������ټ���������\n");
        me->set_temp("pending/practice", 0);
        me->set_temp("pending/practicing_skill", 0);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : yanlian <����>

���ָ��������㽫ĳЩ�书�϶�Ϊһ����Ϊһ��ǿ��ö���¼��ܡ����罵��
ʮ���ơ������ʮ����һһѧȫ����Ϳ�����������ʮ����(xianglong-zhang)��
һ���ɹ����㽫����һ��ȫ�µļ��ܡ��������ķѾ������������������Ϊ��
Щ���ز������㣬������ʧ�ܡ�
HELP
        );
        return 1;
}
